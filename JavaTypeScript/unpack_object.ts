var obj1 = {
    uname: "rcf",
    age: 18,
    address: "home",
    information: {
        firstName: "r",
        lastName: "cf"
    },
    "test": "2", // tyepscript 中 都可以这样[], .都可以访问
    sayHello: function () {}
}

// 类型要相同，就是函数的类型要相同
obj1.sayHello = function () {
    console.log("Hello " + this.uname)
}

obj1.sayHello()


var { uname, age} = obj1;
console.log(uname, age, obj1["age"])

// 层级解析，跟javascript不同不能指定不存在属性
var { uname, age:mage, information: {firstName, lastName}} = obj1

console.log(uname, mage, firstName, lastName)

var mList1 = ["hello", "rcf", "welcome"]
var mList2 = ["hello", ["rcf", "welcome"]]
var [, , z] = mList1
var [c, [a, b]]:any = mList2 // 这里要any，要不然typescript把里面的元素都当做同等元素了，这样就报错了
console.log(c, a, b)
var x:number = 1; var y:number = 2;
[x, y] = [y, x]