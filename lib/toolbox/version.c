#include "version.h"

struct Version {
    const char* git_hash;
    const char* git_branch;
    const char* git_branch_num;
    const char* build_date;
    const char* version;
    const uint8_t target;
    const bool build_is_dirty;
};

/* version of current running firmware (bootloader/flipper) */
static const Version version = {
    .git_hash = GIT_COMMIT,
    .git_branch = GIT_BRANCH,
    .git_branch_num = GIT_BRANCH_NUM,
    .build_date = BUILD_DATE,
    .version = VERSION
#ifdef FURI_RAM_EXEC
    " (RAM)"
#endif
    ,
    .target = TARGET,
    .build_is_dirty = BUILD_DIRTY,
};

const Version* version_get(void) {
    return &version;
}

const char* version_get_githash(const Version* v) {
    return v ? v->git_hash : version.git_hash;
}

const char* version_get_gitbranch(const Version* v) {
    return v ? v->git_branch : version.git_branch;
}

const char* version_get_gitbranchnum(const Version* v) {
    return v ? v->git_branch_num : version.git_branch_num;
}

const char* version_get_builddate(const Version* v) {
    return v ? v->build_date : version.build_date;
}

const char* version_get_version(const Version* v) {
    return v ? v->version : version.version;
}

uint8_t version_get_target(const Version* v) {
    return v ? v->target : version.target;
}

bool version_get_dirty_flag(const Version* v) {
    return v ? v->build_is_dirty : version.build_is_dirty;
}