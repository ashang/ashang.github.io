---
title: django-flutter
date: 2018-08-11
tags: Example
---

<https://stackoverflow.com/questions/55785581/socketexception-os-error-connection-refused-errno-111-in-flutter-using-djan>

SocketException: OS Error: Connection refused, errno = 111 in flutter using django backend


I m building a flutter app with django rest-framework. The registration api is working fine in Postman but after some successful registration from the flutter app it is showing the above error. The request is been sent on https address.

Request:

var data = {'email':signupemailidcontroller.text,
            'password1':passwordcontroller.text,
            'password2':confirmpasswordcontroller.text,
           };
        //http request here
        await http.post(websitesignupurl,
                        headers: headers,
                        body: json.encode(data))
          .then((onResponse){
            print(onResponse.body);
          }).catchError((onerror){
            print(onerror.toString());
        });

Output in Console:

SocketException: OS Error: Connection refused, errno = 111

I Expect the response of this request to be a Json object containing the user and token.


If you're running the server locally and using the Android emulator, then your server endpoint should be 10.0.2.2:8000 instead of localhost:8000 as AVD uses 10.0.2.2 as an alias to your host loopback interface (i.e) localhost

Note on Futures

I noticed above that the code is using await and then on the same line. This can be confusing, to be clear, await is used to suspend execution until a future completes, and then is a callback function to execute after a future completed. The same could be written as below

void myFunction() async {
    var data = {};
    var response = await http.post(URL, headers:headers, body:data);
    if (response.statusCode == 200) {
        print(reponse.body);
    } else {
       print('A network error occurred');
    }
}

or the non async/await method

void myFunction() {
    var data = {};
    http.post(URL, headers:headers, body:data)
    .then((response) => print(response.body))
    .catchError((error) => print(error));
}

For a more detailed information on Futures in Dart please read https://www.dartlang.org/tutorials/language/futures




adb reverse tcp:3001 tcp:3001

you can also read about adb and networking via going through below mentioned page https://developer.android.com/studio/command-line/adb.html



https://dart.dev/codelabs/async-await


https://i.stack.imgur.com/eXPS2.png


Dart is a client-optimized language for fast apps on any platform


Optimized
for UI
Develop with a programming language specialized around the needs of user interface creation
Productive
development
Make changes iteratively: use hot reload to see the result instantly in your running app
Fast on all
platforms
Compile to ARM & x64 machine code for mobile, desktop, and backend. Or compile to JavaScript for the web


https://medium.com/dartlang/announcing-dart-2-12-499a6e689c87


