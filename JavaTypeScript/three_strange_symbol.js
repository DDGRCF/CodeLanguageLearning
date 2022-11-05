function myFunc(maybeString) {
    // const onlyString: string = maybeString; // 编译错误 
    var ignoreUndefinedAndNull = maybeString; // 忽略空声明
    console.log(ignoreUndefinedAndNull); // 打印为空
}
myFunc(undefined); // 可以运行但是忽略空声明
function myFunc2(numGenerator) {
    // const num1 = numGenerator(); // 编译错误
    var num2 = numGenerator(); // 调用函数忽略空声明
    console.log(num2); // 无法运行
}
// myFunc2(undefined);
function tryGetArrayElement(arr, index) {
    if (index === void 0) { index = 0; }
    return arr === null || arr === void 0 ? void 0 : arr[index];
}
var test = tryGetArrayElement(undefined, 2);
console.log(test);
