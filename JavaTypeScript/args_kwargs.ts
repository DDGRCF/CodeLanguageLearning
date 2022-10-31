// javaScript
// function jAddNumbers() {
//     var nums = [];
//     for (var _i = 0; _i < arguments.length; _i++) {
//         console.log(arguments[_i]);
//     }
// }

// jAddNumbers(1, 2, 3, 4);

// typeScript 中使用这个
function tAddNumbers(...nums: number[]) {
    for (var _i = 0; _i < nums.length; _i++) {
        console.log(nums[_i]);
    }

}

tAddNumbers(1, 2, 3, 4);