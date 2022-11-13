let aArray = ['a',123,{a:'1',b:'2'}];
aArray["name"] = "array";

// https://segmentfault.com/q/1010000006658882
// 循环key，而且还会遍历出自定义属性
for (let index in aArray) {
    console.log(index);
} // result: [0, 1, 2, name]

// 循环value
for (let value of aArray) {
    console.log(value);
} // result: [a, 123, {a: "1", b: "2"}]，这个不会遍历出自定义属性 当时不能遍历普通对象

var student={
    name:'wujunchuan',
    age:22,
    locate:{
    country:'china',
    city:'xiamen',
    school:'XMUT'
    }
}

for(var key of Object.keys(student)){ // 遍历普通对象要使用Object.keys()
    //使用Object.keys()方法获取对象key的数组
    console.log(key+": "+student[key]);
}