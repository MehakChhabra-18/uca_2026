function* calculator(initialValue) {

    let result = initialValue;

    while (true) {

        let input = yield result;

        if (!input || typeof input !== "object") {
            console.log("Invalid input");
            continue;
        }

        let operation = input.operation;
        let value = input.value;

        if (
            operation !== "add" &&
            operation !== "subtract" &&
            operation !== "multiply" &&
            operation !== "divide"
        ) {
            console.log("Invalid operation");
            continue;
        }

        if (typeof value !== "number") {

            if (
                operation === "multiply" &&
                typeof value === "string" &&
                !isNaN(value)
            ) {
                value = Number(value);
            } 
            else {
                console.log("Invalid input");
                continue;
            }
        }


        if (operation === "divide" && value === 0) {
            console.log("Cannot divide by zero");
            continue;
        }

        switch (operation) {

            case "add":
                result = result + value;
                break;

            case "subtract":
                result = result - value;
                break;

            case "multiply":
                result = result * value;
                break;

            case "divide":
                result = result / value;
                break;
        }

        console.log(result);
    }
}



let calc = calculator(50);
console.log(calc.next());

calc.next({
    operation: "add",
    value: 30
}); 

calc.next({
    operation: "multiply",
    value: "2"
});

calc.next({
    operation: "add",
    value: "30"
});

calc.next({
    operation: "multiply",
    value: 0
});