// javaScript
// function jAddNumbers() {
//     var nums = [];
//     for (var _i = 0; _i < arguments.length; _i++) {
//         console.log(arguments[_i]);
//     }
// }
// jAddNumbers(1, 2, 3, 4);
// typeScript 中使用这个
function tAddNumbers() {
    var nums = [];
    for (var _a = 0; _a < arguments.length; _a++) {
        nums[_a] = arguments[_a];
    }
    for (var _i = 0; _i < nums.length; _i++) {
        console.log(nums[_i]);
    }
}
tAddNumbers(1, 2, 3, 4);
