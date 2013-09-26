
#include <vector>

using namespace std;

/**



*/

namespace mongo { 
    
    class NS;
    class DiskLoc;
    class DB;

    class ScopedExtent { 
        ScopedExtent(const DB&, DiskLoc);
        unsigned dataSize() const;
        char* data();
        const char* data() const;
        DiskLoc loc() const;
    };
    class ExtentManager { 
        ScopedExtent alloc(unsigned sizeHint, DiskLoc& loc);
        void remove(DiskLoc extLoc);
    };

    namespace s2 { 
    }

}

