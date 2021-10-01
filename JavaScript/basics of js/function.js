console.log("let's start with functions");
console.log("please enter a number to find out if its prime or not");
let sc= process.argv;
let a=parseInt(sc[2],10);
if(isprime(a)==true){
    console.log("the number",a," is prime");
}
else{
    console.log("the number",a," is not prime");
}
function isprime(x){
    for(let f=2;f*f<=x;f++){
        if(x%f==0){
            return false;
        }
    }
    return true;
}