const fields = [
  "First Name",
  "Last Name",
  "Email"
];

function generateForm() {
  return fields.map(field => `
    <label>${field}</label>
    <input type="text"><br><br>
  `).join("");
}

document.getElementById("form-container").innerHTML = generateForm();