### Quadtree
**written in c**

### Prerequisites
In order to launch the game you need to install the The [MLV library](http://www-igm.univ-mlv.fr/~boussica/mlv/api/French/html/installation.html) which is a simplified multimedia library.

### PURPOSE OF THE DUTY
Make a quadTree command with the following manual page: 

**NAME**
	quadTree - Puzzle game
	
### DESCRIPTION 
The quadTreed command gives access to a menu allowing the following choices:

 - open a 256 grayscale image in jpg format,
 
 - open a file containing a quartic tree representation of a square image
 - choose to cut the image into 16 pieces

 

 - choose to cut the image into 64 pieces
 - leave

The heart of the project is the creation and manipulation of a quartic tree.
When you choose to load a .jpg image, the file containing the representation by a quartic tree is immediately created (if it did not exist); it has the same base name as the image file but the suffix .quad replaces .jpg.