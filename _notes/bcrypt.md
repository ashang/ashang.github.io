

store the password with the industry standard bcryptjs or bcrypt to protect them.

bcrypt uses a form of encryption to convert your password into a very large number that's easy to confirm, but difficult to reverse engineer with only the number. When you give my server your password I run it through the same encryption and if it comes equal to what I have in the database (more or less), then I know you gave me the correct one.

What makes bcrypt secure is someone with this large number has to spend a lot of time feeding bad passwords through bcrypt--requiring expensive CPU usage--

