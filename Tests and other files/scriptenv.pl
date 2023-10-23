use Env;

#printhead
print ('<!DOCTYPE html>
<html lang="en">
<head>
    <title>
        42webserver-os environment
    </title>   
</head>
<body>
    <h2 style="text-align: center;"><strong>THESE ARE YOUR ENVIRONMENT VARIABLES:</strong></h2>',"\n");

#printenv

print ("<p>","\n");
for (keys %ENV) 
{ 
  print "$_  =  $ENV{$_}\n";
  print ("<br>","\n");
}
print ("<p>","\n");

#printend
print ('<hr>
<h5>
    FROM WIKIPEDIA:
    <i>Environment variables are part of the environment in which a process runs. 
    For example, a running process can query the value of the TEMP environment variable 
    to discover a suitable location to store temporary files, or the HOME or USERPROFILE variable 
    to find the directory structure owned by the user running the process.</i>
</h5>
<br><br><body>
</body>
<footer>
<h6>
<i>cgi environment for 42webwerver.<br>This was scripted in perl.</i>
</h6>
</footer>

</html>',"\n");
