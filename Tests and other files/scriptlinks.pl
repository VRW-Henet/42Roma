use feature qw(switch);

#printhead
print ('<!DOCTYPE html>
<html lang="en">
<head>
    <title>
        Story of Internet
    </title>   
</head>
<body>
    <h1 style="text-align: center;"><strong>WOW!</strong></h1>',"\n");

#printlinks
$number = int(rand(4));
print ($number,"/3:","\n");

print ("<p>","\n");
if ($number == 0)
{
  print ("Free money");
}
if ($number == 1)
{
  print ("Ehy! what's this song?");
}
if ($number == 2)
{
  print ("Shrek is love but yt got the video down");
}
if ($number == 3)
{
  print ("A wizard is never off-tempo");
}
print ("<br>","\n");
print ("<p>","\n");
print ("<a href='");
if ($number == 0)
{
  print ("https://www.youtube.com/watch?v=dQw4w9WgXcQ");
}
if ($number == 1)
{
  print ("https://www.youtube.com/watch?v=y6120QOlsfU");
}
if ($number == 2)
{
  print ("https://www.youtube.com/watch?v=6Dh-RL__uN4");
}
if ($number == 3)
{
  print ("https://www.youtube.com/watch?v=Sagg08DrO5U");
}
print ("'>HERE!</a>");
print ("\n","<br>");

#printend
print ('<hr>
<h5>
    FROM WIKIPEDIA:
    <i>A meme is an idea, behavior, or style that spreads by means of imitation from person to person<br>
    within a culture and often carries symbolic meaning representing a particular phenomenon or theme.<br> 
    A meme acts as a unit for carrying cultural ideas, symbols, or practices, that can be transmitted<br> 
    from one mind to another through writing, speech, gestures, rituals, or other imitable phenomena<br> 
    with a mimicked theme.</i>
</h5>
<br><br><body>
</body>
<footer>
<h6>
<i>cgi environment for 42webwerver.<br>This was scripted in perl.</i>
</h6>
</footer>

</html>',"\n");
