<?php
include('functions.php'); 
 include('connection.php');
if(isset($_GET['data']))
{
  $data = validateFormData($_GET['data']);    
  
 $query = "INSERT INTO `testdata` (`id`, `details`, `time`, `statys`) VALUES (NULL, '" .  $data . "', CURRENT_TIMESTAMP, 'Y')";

       $result1 = mysqli_query($conn, $query);
        
        if($result1 == false)
        {  
         echo 'Failed';
            
        }
	   else
        {
           echo 'Success';
        }
    }
?>