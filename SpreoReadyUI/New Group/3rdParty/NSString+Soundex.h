#import <UIKit/UIKit.h>


@interface NSString (Soundex)

- (NSString*)soundexString;
- (BOOL)soundsLikeString:(NSString*) aString;

@end
