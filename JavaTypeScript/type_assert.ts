// https://jkchao.github.io/typescript-book-chinese/typings/typeAssertion.html#%E7%B1%BB%E5%9E%8B%E6%96%AD%E8%A8%80%E8%A2%AB%E8%AE%A4%E4%B8%BA%E6%98%AF%E6%9C%89%E5%AE%B3%E7%9A%84
interface Person {
    test1: string,
    test2: string,
    say: ()=>string
}

var p1: Person = {
    test1: "r",
    test2: "cf",
    say: (): string => {
        return this.test1 + this.test2;
    }
}
var p2 = {
    test1: 'w',
    test2: "jbla",
    say: (): string => {
        return this.test1 + "|" + this.test2;
    }
} as Person;


console.log("p1: " + JSON.stringify(p1));
console.log("p2: " + JSON.stringify(p2));
