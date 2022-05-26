Stuff to keep in mind when doing the input error checker.
- **Camera:** Return error when the angle <0 or >180. If the angle =0 or =180, we'll need to manually increase the FOV a few decimals.
- **Vectors:** We can return errors if an x,y,z value is <-1 or >1, but we can still manage them.
- **Colors:** Return error when an r,g,b value <0 or >255.
- **Brightness:** Return error when a value <0 or >1. We can still manage values over 2, but we shouldn't. 

- There should only be one ambient light and one camera. 
- For the mandatory part, we should only have one light without color, but we can manage colors and multiple lights in the bonus part.