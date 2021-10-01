 function mSort (array) {
      if (array.length === 1) {
      return array                        // returns if we hit an array with a single element
   }
   const mid = Math.floor(array.length / 2) //rounded off middle element of array
   const left = array.slice(0, middle)         // elements on the left 
   const right = array.slice(middle)           // elements on the right 
   document.write(mid);
   return merge(
      mSort(left),
      mSort(right)
   )
   }
   // compare the arrays element by element and return the result
   function merge (left, right) {
      let result = []
      let leftIndex = 0
      let rightIndex = 0
      while (leftIndex < left.length && rightIndex < right.length) {
         if (left[leftIndex] < right[rightIndex]) {
         result.push(left[leftIndex])
         leftIndex++
         document.write("</br>");        
         } else {
         result.push(right[rightIndex])
         rightIndex++      
      }
   }
   return result.concat(left.slice(leftIndex)).concat(right.slice(rightIndex))
   }
   const list = [4,7,5,9,1,3,8,2]
   document.write(mSort(list));
   //Time Complexity
   //The average,worst and best case complexities of this program is O(nlogn)
   //Space Complexity
   //Space Complexity of this program is O(n)