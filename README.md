# MiniSystem
This is a small javascript runtime targeted mainly at embedded environments.

## The idea
The goal is to have a small environment based on javascript. It will have access to one root directory that will act as its drive like on old operating systems. In that directory will be a file called startup.js or something like that that will run at the beggining. The whole project is supposed to be modular and platform independant.

## How to contribute
Fork the repo, then create a new branch named after the feature that you want to add. If it's a core feature like a new interface then make it start with core_(feature name). If it's a port than name it port_(port name)_(feature name(the feature name can be ommited if it's not necessary)). Than create a pull request.

## What to keep in mind when contributing
All tasks for the core that need to be done are in TASKS.md. There are also instructions how to take a task on. I encourage you, if you are working on a port than also keep all tasks in a simmilar format in the port directory as TASKS.md. This is so that other people can look what needs to be done and help out.