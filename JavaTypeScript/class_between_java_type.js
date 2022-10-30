// typescript
var TSite = /** @class */ (function () {
    function TSite() {
    }
    TSite.prototype.name = function () {
        console.log("TypeScript class");
        console.log(this.test);
    };
    return TSite;
}());
;
var JSite = (function () {
    function JSite() {
        this.test;
    }
    JSite.prototype.name = function () {
        console.log("JavaScript class");
        console.log(this.test);
    };
    return JSite;
}());
var javascriptObj = new JSite();
javascriptObj.test = "java script test";
javascriptObj.name();
var typescriptObj = new TSite();
typescriptObj.test = "type script test";
typescriptObj.name();
