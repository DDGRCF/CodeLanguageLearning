function myFunc(maybeString: string | undefined | null) {
    // const onlyString: string = maybeString; // 编译错误 
    const ignoreUndefinedAndNull: string = maybeString!; // 忽略空声明
    console.log(ignoreUndefinedAndNull); // 打印为空
}

myFunc(undefined); // 可以运行但是忽略空声明

type NumGenerator = () => number;

function myFunc2(numGenerator: NumGenerator | undefined) {
    // const num1 = numGenerator(); // 编译错误
    const num2 = numGenerator!(); // 调用函数忽略空声明
    console.log(num2); // 无法运行
}

// myFunc2(undefined);

function tryGetArrayElement<T>(arr?: T[], index: number=0) {
    return arr?.[index]; 
}

var test = tryGetArrayElement(undefined, 2);
console.log(test); // 返回undfined，其实就停止运行方程

// 具体: https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Operators/Nullish_coalescing
var a = null ?? false; // 左侧为null或undefined时，其返回右侧操作数，否则返回左侧操作数
