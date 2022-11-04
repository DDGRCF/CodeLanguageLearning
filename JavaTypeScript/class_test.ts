class Test {
    constructor(uname:string, age: number) {
        this.uname = uname;
        this.age = age;
    } 
    uname: string;
    age: number;
    greeting(): void {
        console.log("name: " + this.uname + " " + "age: " + this.age);
    }
}

// 不用构造函数
// var test: Test = new Test();
// test.age = 18;
// test.uname = "rcf";
// test.greeting();

// 使用构造函数
var test: Test = new Test("rcf", 18);
test.greeting();