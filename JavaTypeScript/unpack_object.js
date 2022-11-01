var _a;
var obj1 = {
    uname: "rcf",
    age: 18,
    address: "home",
    information: {
        firstName: "r",
        lastName: "cf"
    },
    "test": "2",
    sayHello: function () { }
};
// 类型要相同，就是函数的类型要相同
obj1.sayHello = function () {
    console.log("Hello " + this.uname);
};
obj1.sayHello();
var uname = obj1.uname, age = obj1.age;
console.log(uname, age, obj1["age"]);
// 层级解析，跟javascript不同不能指定不存在属性
var uname = obj1.uname, mage = obj1.age, _b = obj1.information, firstName = _b.firstName, lastName = _b.lastName;
console.log(uname, mage, firstName, lastName);
var mList1 = ["hello", "rcf", "welcome"];
var mList2 = ["hello", ["rcf", "welcome"]];
var z = mList1[2];
var c = mList2[0], _c = mList2[1], a = _c[0], b = _c[1];
console.log(c, a, b);
var x = 1;
var y = 2;
_a = [y, x], x = _a[0], y = _a[1];
