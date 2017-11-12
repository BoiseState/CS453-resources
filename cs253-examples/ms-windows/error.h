#ifndef ERROR_H_98B80DA6_853B_4914_9B0A_EF41D19BB57A
#define ERROR_H_98B80DA6_853B_4914_9B0A_EF41D19BB57A

// Error codes
#define CREATE_PROCESS_FAILED -1
#define BUILT_IN_CD_HOME_FAILED -2
#define BUILT_IN_CD_NEW_FAILED -3

extern char *pname;

void err_ret(const char *fmt, ...);
void err_sys(const char *fmt, ...);
void err_dump(const char *fmt, ...);
void err_msg(const char *fmt, ...);
void err_quit(const char *fmt, ...);

#endif // ERROR_H_98B80DA6_853B_4914_9B0A_EF41D19BB57A