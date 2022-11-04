var Test = /** @class */ (function () {
    function Test(uname, age) {
        this.uname = uname;
        this.age = age;
    }
    Test.prototype.greeting = function () {
        console.log("name: " + this.uname + " " + "age: " + this.age);
    };
    return Test;
}());
// 不用构造函数
// var test: Test = new Test();
// test.age = 18;
// test.uname = "rcf";
// test.greeting();
// 使用构造函数
var test = new Test("rcf", 18);
test.greeting();
