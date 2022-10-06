#include <iostream>
#include <cassert>

#define MALLOC_ALIGN 16
/* 
    这里的前面指的的是上一层的意思 就是unsigned char* 取*或者[]后的上一层就是unsigned char 
    // 采用类比的方式解释
    unsigned char *a = new char[5];
    // a + 1 表示从a指针指向的地址走了1个字节, 为啥是1个字节
    // 因为unsigned char *a前面是unsigned char, unsigned char是1个字节

    unsigned char **b = (unsigned char **)a;
    // 同理, b + 1 表示从b指针指向的地址走了8个字节, 为啥是8个字节
    // 因为unsigned char **b前面是unsigned char*, unsigned char*是8个字节
    // unsigned char*是个指针类型, 指针类型占8字节的大小

    // 总结: 指针的加减 可以看做去掉一个*, 然后看前面的类型占多少字节

    // 所以
    (unsigned char**)udata + 1
    // 表示udata指向的类型为unsigned char*(是一个指针类型占8字节), 再加一, 即udata从指向的地址
    // 往前走了8个字节
*/

/* 
    对于32位系统，都是4个字节读取数据；对于64位系统，都是8个字节读取数据；
    若不按照这个倍数读取的话，就需要读取两次，开销更大
*/

template<typename _Tp>
static inline _Tp* alignPtr(_Tp* ptr, int n = (int)sizeof(_Tp)) {
  return (_Tp*)(((size_t)ptr + n - 1) & -n);
}

static inline size_t alignSize(size_t sz, int n) {
    return (sz + n - 1) & -n;
}

static inline void* fastMalloc(size_t size) {
    unsigned char * udata = (unsigned char *) malloc(size + sizeof(void *) + MALLOC_ALIGN);
    if (!udata) return 0;
    unsigned char ** adata = alignPtr((unsigned char**)udata + 1, MALLOC_ALIGN);
    adata[-1] = udata;
    return adata;
}

static inline void fastFree(void *ptr) {
    if (ptr) {
        unsigned char * udata = ((unsigned char **)ptr)[-1];
        free(udata);
    }
}

class TestClass {
    public:
        int a;
        int b;
        TestClass(const int & a, const int & b) {
            this->a = a;
            this->b = b;
        }

        TestClass (TestClass & p) {
            if (&p == this) {
                return;
            }
            p.a = a;
            p.b = b;
        }

};

int main() {
    // int *p = new int[6];
    // size_t x = (size_t) p;
    // std::cout << x << std::endl;
    // assert(x % 16 == 0);

    int *a = new int (5);
    std::cout << "a: " << a << std::endl;
    std::cout << "(size_t)a: " << (size_t)a << std::endl;
    std::cout << "(ll)a: " << (long long)a << std::endl;
    size_t totalsize1 = alignSize(12, 4); // 12字节 的 4 字节对齐
    size_t totalsize2 = alignSize(17, 4); // 17字节 的 4 字节对齐

    std::cout << "totalsize: " << totalsize1 << std::endl;
    std::cout << "totalsize: " << totalsize2 << std::endl;

    void* data = fastMalloc(totalsize2);
    std::cout << "data: " << data << std::endl;
    std::cout << "(void *)data: " << (void *)data << std::endl;
    std::cout << "(int *)data: " << (int *)data << std::endl;
    std::cout << "(float *)data" << (float *) data << std::endl;
    fastFree(data);

    // void* data = fastMalloc(totalsize);

    return 0;
}