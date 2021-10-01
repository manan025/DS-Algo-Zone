console.log("let's see how we take input in JavaScript");
let sc= process.argv;
let no=sc[2];
console.log("the number which you have passed as an input is", no);
console.log(typeof no);
let no2=parseInt(sc[3],10);
console.log("the number which you have passed as an input is", no2);
console.log(typeof no2);