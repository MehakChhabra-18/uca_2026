const worker = new Worker("worker.js");

worker.onmessage = function (event) {
    if (event.data.error) {
        console.error(event.data.error);
    } else {
        event.data.forEach(user => {
            console.log(`${user.name} - ${user.active ? "Active" : "Inactive"}`);
        });
    }
};

worker.onerror = function (error) {
    console.error("Worker Error:", error.message);
};