### Any bit of x equals 1:  
```
!!x
```
### Any bit of x equals 0:
```
!!(~x) /* !!(~111 = 000) = 0 */ /* !!(~011 = 100) = 1 */
```
### Any bit in the·least significant byte of x equals 1
```
!!(x & 0xFF)
```
### Any bit in the most significant byte of x equals 0
```
!!(~(x | ~(0xFF << ((sizeof(int) - 1) * 8))))
```
