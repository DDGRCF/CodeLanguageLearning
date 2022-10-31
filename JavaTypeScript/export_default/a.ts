// export 指定模块默认导出的配置
export default {
    uname:"rcf",
    age: 18,
    aPrint: function () {
        console.log("uname: " + this.uname + "; age: " + this.age);
    }
}