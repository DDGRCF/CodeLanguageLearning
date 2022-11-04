interface Test2 {
    uname: string,
    age: number,
    greet: ()=>string // 这里是()=>string 参数放回类型
}


var test2: Test2 = {
    uname: "rcf",
    age: 18,
    greet: (): string=>{
        return "Hi ";
    } // 这里是(): string=>{} 参数 返回类型 函数体
}
