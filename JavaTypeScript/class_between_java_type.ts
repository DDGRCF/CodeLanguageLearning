// typescript
class TSite {
    name():void {
        console.log("TypeScript class");
        console.log(this.test);
    }
    test: string;
};



var JSite = (
    function() {
        function JSite() {
            this.test;
        }
        JSite.prototype.name = function() {
            console.log("JavaScript class");
            console.log(this.test);
        };
        return JSite;
    }()
);    



var javascriptObj = new JSite();
javascriptObj.test = "java script test";
javascriptObj.name();

var typescriptObj = new TSite();
typescriptObj.test = "type script test";
typescriptObj.name();