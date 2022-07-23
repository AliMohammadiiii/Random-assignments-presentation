# Random-assignments-presentation
This Program develop with C++
The purpose of this exercise is to familiarize you with input and output and working with strings and vectors in C++ language as basic skills.
Programming is in this language. These skills enable the implementation of larger projects.

**Abstract:**
In the current semester, the professor of software engineering asked the students to form groups of three to complete the course assignments. At In this lesson, students are given a number of assignments that must be done in groups. After completing each task, a number of Students are selected for delivery online and their list is announced one day before the delivery date. How to choose should So that each student has at least one delivery per semester, but some students have more than one delivery will have.
The professor plans to set the delivery schedule from the beginning of the semester (without informing the students). Therefore, the problem It is to produce the delivery schedule by having the list of course students and the list of group members. That is, specify for Each assignment, which students must participate in the online delivery. The generated program must meet the following conditions.
Condition 1. For each assignment, each group should not have more than one delivery 
Condition 2. The order of delivery of groups over time is randomly determined and related to the order of the list of groups and the order does not have group members (for example, not in the same order or vice versa).
Condition 3. All students must deliver at least once

The purpose of condition 2 is that students cannot predict anything about the order of deliveries practically have to do everything Contribute assignments and prepare for possible delivery. That is why it is necessary in this planning Use random number generation

K = number of groups
A = number of assignment
S = Number of deliveries for each assignment


**Random selection algorithm** To find random numbers, we use the rand() function, but the random function returns duplicate numbers if we use it several times. For this reason, we always use the srand() function before using the rand() function, but in order to give a number to srand() so that the base of the calculation is a random number, we use an int variable that every time We added a number to it. And it is used everywhere.Then, in order for it to be in the range we want, we get the remainder of the result (rand) in that number and put it. And in order for everyone to present once, we create a new list, one by one, each time we enter a person from the list and add it to the new list, and after finishing the list, we read an entry from the new list. we read ; Delete
