var aArray = ['a', 123, { a: '1', b: '2' }];
aArray["name"] = "array";
// 循环key
for (var index in aArray) {
    console.log(index);
} // result: [0, 1, 2]
// 循环value
for (var _i = 0, aArray_1 = aArray; _i < aArray_1.length; _i++) {
    var value = aArray_1[_i];
    console.log(value);
} // result: [a, 123, {a: "1", b: "2"}]
