#include <linux/bpf.h>
#include <stdbool.h>
#include <stdint.h>
#include <bpf_helpers.h>

DEFINE_BPF_MAP(cpu_pid_map, ARRAY, int, uint32_t, 1024);

struct switch_args {
    unsigned long long ignore;
    char prev_comm[16];
    int prev_pid;
    int prev_prio;
    long long prev_state;
    char next_comm[16];
    int next_pid;
    int next_prio;
};

DEFINE_BPF_PROG("tracepoint/sched/sched_switch", AID_ROOT, AID_SYSTEM, tp_sched_switch)
(struct switch_args *args) {
int key;
uint32_t val;

key = bpf_get_smp_processor_id();
val = args->next_pid;

bpf_cpu_pid_map_update_elem(&key, &val, BPF_ANY);
return 1; // return 1 to avoid blocking simpleperf from receiving events
}

LICENSE("GPL");
