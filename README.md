# Google Hash Code 2019 Practice Problem

Here it is!

## Getting Started

By following this instructions you will have a working binary.

### Prerequisites

You only need the source code, either by cloning the project or by downloading it, and a C compiler.

 - **Windows**
To compile the project in Windows (without any changes to the makefile) you'll need a compiler that supports C18. The project has been tested to work with MinGW-64. The lastest version of Cygwin (last checked 20/11/2018) has an older version of GCC that doesn't support C18.

 - **GNU-Linux**
To compile the project you'll need a C compiler that supports C18 (again). GCC versions >= 8 works with the provided makefile (last checked 20/11/2018).

### Installing

If you've tried before to build the project, you may want to clean it before trying to build it again.
If it's the first time you build it, it's safe to skip this step.
The cleaning can be performed by using
 - **Windows** (with MinGW)
```
mingw32-make clean
```
 - **GNU-Linux** (with GCC)
```
make clean
```
After cleaning the project, you can safely build it.
 - **Windows** (with MinGW)
```
mingw32-make
```
 - **GNU-Linux** (with GCC)
```
make
```
You will have the binary in *bin/HashCodeTest.exe*.

## Testing

TBA

## Deployment

TBA

## Built With

* [MinGW-w64](https://sourceforge.net/projects/mingw-w64/) - Build tools for Windows systems
* [GCC](https://gcc.gnu.org/) - C compiler for GNU-Linux systems.

## Contributing

Feel free to create pull requests. Keep in mind that the requests must be synced to the *main* branch. If they have conflicts they'll be rejected.
Also, the pull requests must have a brief explaination of the work done.
They must be free of any binary file and the code has to be indented (plain code won't be accepted).
The code must also follow the GNU C coding style [guideline](https://developer.gnome.org/programming-guidelines/stable/c-coding-style.html.en).

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags](https://github.com/Mowstyl/QSimovC/tags) section on this repository.

## Authors

* **Hernán Indíbil de la Cruz Calvo** - *Initial work* - [Mowstyl](https://github.com/Mowstyl)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

When a project has no LICENSE.md file, it's licensed under the most restrictive license (that means copyright). This is **always** true, so keep it in mind when using someone else's code.
At the moment, Copyright is being used. In the future the license may change, maybe MIT license, maybe GNU, who knows?

## Acknowledgments

* **Billie Thompson** - *This README.md was based on the one provided by this person. Great work!* - [PurpleBooth](https://github.com/PurpleBooth)
* **StackEdit** - *Markdown editor used* - [StackEdit](https://stackedit.io/)
