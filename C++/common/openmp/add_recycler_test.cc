#include <iostream>
#include <omp.h>
#include <chrono>
#include <vector>

void add_ori(const std::vector<int> & a, const std::vector<int> & b, std::vector<int> & c)
{
  for(int i=0; i<a.size(); i++)
  {
    c[i] = (a[i] + b[i]);
  }
}

// 改成OpenMP多核加速（并行）：

// #pragma omp parallel for  num_threads(opt.num_threads);
void add_pll(const std::vector<int> & a, const std::vector<int> & b, std::vector<int> & c)
{
  #pragma omp parallel
  for(int i=0; i<a.size(); i++)
  {
    c[i] = (a[i] + b[i]);
  }
}


int main() {
    // 编译后面加-fopenmp, 由于clock采用的滴答计时，多线程滴答计时，若多线程则时间xnproc增加，不要是你clock计时
    std::vector<int> a(100000, 5);
    std::vector<int> b(100000, 5);
    std::vector<int> c1(100000, 0);
    std::vector<int> c2(100000, 0);

    // omp_set_num_threads(4);
    // auto start_time = std::chrono::system_clock::now();
    double start = omp_get_wtime();
    add_ori(a, b, c1);
    // auto first_time = std::chrono::system_clock::now();
    double end1 = omp_get_wtime();
    add_pll(a, b, c2);
    // auto second_time = std::chrono::system_clock::now();
    double end2 = omp_get_wtime();

    std::cout << "first part: " << end1 - start << std::endl;
    std::cout << "second part: " << end2 - end1 << std::endl;

    // auto first_part = std::chrono::duration_cast<std::chrono::microseconds>(first_time - start_time).count();
    // auto second_part = std::chrono::duration_cast<std::chrono::microseconds>(second_time - first_time).count();
    // std::cout << "first time: " << first_part << std::endl;
    // std::cout << "second time: " << second_part << std::endl;

    return 0;
}