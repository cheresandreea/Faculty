# PHP Web Application Lab

In this lab, you will have to develop a server-side web application in PHP. The web application has to manipulate a MySQL database with 1 to 3 tables and should implement the following base operations on these tables: select, insert, delete, update. Also, the web application must use AJAX for getting data asynchronously from the web server and the web application should contain at least 5 web pages (client-side HTML or server-side PHP).

For the database, you can use the MySQL database on www.scs.ubbcluj.ro. On this MySQL server, you have an account, a password, and a database, all identical to your username and password on the SCS network.

Please make sure that you avoid SQL injection attacks when working with the database.

Have in mind the user experience when you implement the problem:
- Add different validation logic for input fields.
- Do not force the user to input an ID for an item if they want to delete/edit/insert it; this should happen automatically (e.g., the user clicks an item from a list, and a page/modal prepopulated with the data for that particular item is opened, where the user can edit it).
- Add confirmation when the user deletes/cancels an item.
- Do a bare minimum CSS that at least aligns the various input fields.

Documentation can be found at:
1. [http://www.cs.ubbcluj.ro/~forest/wp](http://www.cs.ubbcluj.ro/~forest/wp)
2. [http://www.php.net/manual/en](http://www.php.net/manual/en)
3. [http://www.w3schools.com/php](http://www.w3schools.com/php)
4. [http://www.w3schools.com/ajax](http://www.w3schools.com/ajax)

## Problems

Write a web application for managing food recipes. The application should maintain various information about a recipe in the database (i.e., author, name, type, the actual recipe, etc.). The application should implement: recipes browsing (use AJAX for retrieving recipes of a specific type), adding, removing, and updating a recipe. Also, on the browsing page, the filter used for the previous browsing action (i.e., recipe type) should be displayed (do this in JavaScript).
