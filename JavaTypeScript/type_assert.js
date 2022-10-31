var _this = this;
var p1 = {
    test1: "r",
    test2: "cf",
    say: function () {
        return _this.test1 + _this.test2;
    }
};
var p2 = {
    test1: 'w',
    test2: "jbla",
    say: function () {
        return _this.test1 + "|" + _this.test2;
    }
};
console.log("p1: " + JSON.stringify(p1));
console.log("p2: " + JSON.stringify(p2));
