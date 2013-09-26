
#include <vector>

using namespace std;

/**



*/

namespace mongo { 

    // stubs

    class DiskLoc { 
        unsigned long long x;
    };

    // ---

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

    class VLoc;
    class ScopedRecord { 
        ScopedRecord(const DB&, VLoc);
        ScopedRecord(const DB&, DiskLoc);
        bool fitsInRecord(unsigned size) const;
        // unsigned recSize() const;
        char* data(); // e.g. bson or btree bucket
        const char* data() const;
        VLoc loc() const;
        void grow(unsigned newSize);
    };
    class RecordInterface { 
        //ScopedRecord alloc(unsigned sizeMin);
        ScopedRecord insert(const NS&, const char *data, unsigned len);
        void remove(VLoc loc);
    };

    namespace s2 { 
        class NSDetails { 
            DiskLoc firstExtent;
            DiskLoc lastExtent;
        };
    }

}

