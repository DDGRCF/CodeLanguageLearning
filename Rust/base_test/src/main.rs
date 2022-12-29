fn test_in32(x: i32) {
    println!("x is {}", x); // 末尾一定要!
}

fn test_string(x: String) {

}

fn test_t<T>(x: T) {
    x;
}

fn main() {
    println!("Hello, world!");
    let x: i32 = 0;
    test_t(x);
    println!("x is {}", x);
}
