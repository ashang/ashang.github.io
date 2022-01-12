

        1.     In /home/admin path,  execute “mkdir test_key” and “cd test_key”

        2.     Execute command “openssl req -new -newkey rsa:4096 -nodes -keyout test.key -out test.csr”

                 The parameters can be specified with their own info.

                 After this step we will get “test.key” and “test.csr” file.

        3.     Execute command “openssl x509 -req -in verizon.csr -out test.crt -signkey test.key -days 3650”

                 After this step we will get “test.crt”

        4.     Generate the PEM file:

                 Execute command “cat test.key > test.pem” & “cat test.crt >> test.pem”

              And finally we get the “test.pem” file


Make sure the permission is “664”： “chmod 664 /ovs/npb/lighttpd/server.pem”

Restart NPB service： “sudo systemctl restart ovs-npb”




