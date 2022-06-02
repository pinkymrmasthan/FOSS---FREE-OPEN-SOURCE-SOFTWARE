<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<title></title>
	<style type="text/css">
		body{
			height: 500px;
			padding: 30px;
			text-align: center;
			position: absolute;
			margin: auto;
			top: 0ox;
			bottom: 0px;
			right: 0px;
			left: 0px;
		}
		.form-element{
			margin: 30px;
		}
		.red-message{
			    color: red;
    position: absolute;
    text-align: left;
    margin-bottom: 250px;
    margin-top: -56px;
    margin-left: 165px;
		}
	</style>
</head>
<body>
<?php

$nameErr=$emailErr=$genderErr="";
$name=$email=$gender="";

if ($_SERVER['REQUEST_METHOD']=="POST") {
	if (empty($_POST['name'])) {
		$nameErr="Please fill Name here..";
	}
	else{
		$pattern="/^[a-zA-Z\s']+$/";
		$check = preg_match_all($pattern, $_POST['name']);
		if ($check) {
			$name=$_POST['name'];
		}else{
			$nameErr="Enter the correct name..";
		}
	}
	if (empty($_POST['email'])) {
		$emailErr="Please fill email here";
	}
	else{
		$email_pattern=filter_var($_POST['email'],FILTER_VALIDATE_EMAIL);
		if ($email_pattern) {
			$email=$_POST['email'];	
		}
		else{
			$emailErr="Check the email is correct.";
		}
	}
	 if (empty($_POST["gender"])) {
    $genderErr = "Gender is required";
  } else {
    $gender = test_input($_POST["gender"]);
  }
}
  function test_input($data) {
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  return $data;
}
?>
		<form method="POST" action= " <?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">  
			<div class="form-element">
		<label>Enter your name :  </label><input type="text" name="name" required="Please fill the Name here.." placeholder="Type name here"><br><br><br><span class="red-message">* <?php echo $nameErr; ?></span></div>
		<div class="form-element">
		<label>Enter your email :  </label><input type="email" name="email" required="Please fill the Email here.." placeholder="Type email here"><br><br><br><span class="red-message">* <?php echo $emailErr; ?></span></div></div>
		<div class="form-element">
		 Gender:
  <input type="radio" name="gender" <?php if (isset($gender) && $gender=="female") echo "checked";?> value="female">Female
  <input type="radio" name="gender" <?php if (isset($gender) && $gender=="male") echo "checked";?> value="male">Male
  <input type="radio" name="gender" <?php if (isset($gender) && $gender=="other") echo "checked";?> value="other">Other  
  <span class="error">* <?php echo $genderErr;?></span>
  <br><br>	
		<input type="submit" name="submit" value="Submit"><br><br></div>
	</form>
<?php
echo "Your Input"."<br>";
echo $name."<br>";
echo $email."<br>";
echo $gender;
?>
</body>
</html>