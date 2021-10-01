console.log("arrays in javascript");
console.log("please enter the size of array you want to make");
let sc= process.argv;
let size=parseInt(sc[2],10);
let a=[];
for(let x=0;x<size;x++){
    a[x]=parseInt(sc[3+x]);
}
console.log("array before reversing");
console.log(a);
revarr(a);
console.log("array after reversing");
console.log(a);
function revarr(g){
let st=0;
let en=g.length-1;
while(st<=en){
    let temp=g[st];
    g[st]=g[en];
    g[en]=temp;
    st++;
    en--;
}
}
