
//Comp 322
//Prof. Hinton 
//Calculator Java script 



document.addEventListener('DOMContentLoaded', () => {
    const resultsTable = 
document.getElementById('resultsTable').getElementsByTagName('tbody')[0];
    const minElement = document.getElementById('min');
    const maxElement = document.getElementById('max');
    const averageElement = document.getElementById('average');
    const totalElement = document.getElementById('total');

    let results = []; //empty array for min, max, average, total values 

while (true) { // while loop to continue to get inputs from user
    let x = prompt("Enter the first number :");
    if (x === null) break;
    x = parseFloat(x);

    let y = prompt("Enter the second number :");
    if (y=== null) break;
    y = parseFloat(y);

    let operator = prompt("Enter operator (+, -, *, /, %) :");// operators that will be used
    if (operator === null) break;

    let result;
    switch (operator) {
        case '+':
            result = x + y;
            break;
        case '-':
            result = x - y;
            break;
        case '*':
            result = x * y;
            break;
        case '/':
            result = x / y;
            break;
        case '%':
            result = x % y;
            break;
        default:
            alert("Invalid operator!");
            continue;
    
        }
        results.push(result);//push values to Array

        const newRow = resultsTable.insertRow();// values from here will be put into  results table
            newRow.insertCell(0).innerText = isNaN(x) ? "Invalid input" : x;
            newRow.insertCell(1).innerText = operator;
            newRow.insertCell(2).innerText = isNaN(y) ? "Invalid input" : y;
            newRow.insertCell(3).innerText = result;
    }
    
        const newRow2 = summary.insertRow(); // values from here will be put into  summary table
        const sum = results.reduce((acc, val) => acc + val, 0);
            newRow2.insertCell(0).innerText = Math.min(...results);
            newRow2.insertCell(1).innerText = Math.max(...results);
            newRow2.insertCell(2).innerText = sum/results.length;
            newRow2.insertCell(3).innerText = sum;
    
            totalElement.innerText = sum;
            averageElement.innerText = average;
            minElement.innerText = min;
            maxElement.innerText = max;
        
    
    });
    //end of code
    
        
    
    


    




  
      
      


