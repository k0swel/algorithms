'use strict'

/*
 It is my first time, when i start use JavScript and probably this program can be more simplify.
*/


let massiv = [34,31,6,1,67,14,623];


function swap(array, index1, index2) {
    [array[index1], array[index2]] = [array[index2], array[index1]];
}

function fast_sort(array, start=0, end=array.length-1) {
    if (start < end) {
        let pivot_value = massiv[end];
        let wall = start;
        for (let index = start; index < end; index++) {
            if (array[index] < pivot_value) {
                swap(array, index, wall);
                wall++;
            }
        }
        swap(array, wall, end);
        fast_sort(array, 0, wall-1);
        fast_sort(array, wall+1, end);
    }
}

fast_sort(massiv);
console.log(massiv);