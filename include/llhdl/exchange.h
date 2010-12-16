#ifndef __LLHDL_EXCHANGE_H
#define __LLHDL_EXCHANGE_H

struct llhdl_module *llhdl_parse_fd(FILE *fd);
void llhdl_write_fd(struct llhdl_module *m, FILE *fd);

struct llhdl_module *llhdl_parse_file(const char *filename);
void llhdl_write_file(struct llhdl_module *m, const char *filename);

#endif /* __LLHDL_EXCHANGE_H */
