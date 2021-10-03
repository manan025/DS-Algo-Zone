console.log("let's find if the given number is odd or even");
let sc=process.argv;
let a=parseInt(sc[2],10);
if(a%2==0){
    console.log("the given number",a, "is even");
}
else{
    console.log("the given number",a," is odd");
}
