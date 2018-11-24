
var attempt = 3; // Variable to count number of attempts.
// Below function Executes on click of login button.
var data = [{
    "name":"rehan",
    "id": "2",
    "password":"rehan123"
}];
function validate(){
var username = document.getElementById("username").value;
var password = document.getElementById("password").value;
if ( username == "admin" && password == "admin#123"){
// alert ("Login successfully");
window.location = "panel.html"; // Redirecting to other page.
return false;
}
if (data[0].name == username.value && data[0].password == password.value) {
    windows.location = "user.html";
    alert ("Login successfully");

// elif{
// attempt --;// Decrementing by one.
// alert("You have left "+attempt+" attempt;");
// Disabling fields after 3 attempts.
if( attempt == 0){
document.getElementById("username").disabled = true;
document.getElementById("password").disabled = true;
document.getElementById("submit").disabled = true;
return false;
}
}
}
