console.log("for loops in javascript");
let sc= process.argv;
let a=parseInt(sc[2],10);
console.log("the given number is", a);
let count=0;
for(let i=2;i*i<=a;i++){
    if(a%i==0){
       count++;
    }
}
if(count>0){
    console.log("the number",a, "is not prime");
}
else{
    console.log("the number",a, "is prime");
}