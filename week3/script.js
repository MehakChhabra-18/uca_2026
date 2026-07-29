const usersDiv = document.getElementById("users");

if (window.Worker) {

    const worker = new Worker("worker.js");

    worker.postMessage("start");

    worker.onmessage = function (event) {

        const result = event.data;

        if (!result.success) {
            usersDiv.innerHTML = result.error;
            return;
        }

        const users = result.users;

        if (!users || users.length === 0) {
            usersDiv.innerHTML = "No users found";
            return;
        }

        let output = "";

        users.forEach(user => {
            output += `${user.name} - ${user.active ? "Active" : "Inactive"}<br>`;
        });

        usersDiv.innerHTML = output;
    };

} else {
    usersDiv.innerHTML = "Web Workers are not supported.";
}