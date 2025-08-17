#include <debug/debug_stdio.h>
#include <drivers/dt/dt.h>
#include <drivers/dt/dt_props.h>
#include <stdbigos/buffer.h>
#include <stdbigos/types.h>

void main([[maybe_unused]] u32 hartid, const void* fdt) {
	/*
	if (dt_init(fdt) < 0) {
	    dprintf("DT_INIT FAILED");
	    return;
	}


	dt_node_t* root = dt_get_root();
	if (!root) {
	    dprintf("GETTING ROOT FAILED");
	    return;
	}
	    */

	// Showcasing that values and finding work
	// TODO: find any serial or the serial with specific compatible field
	/*
	const char* uart_path = "/soc/serial@10000000";
	dt_node_t* uart = dt_node_find(uart_path);
	if (!uart) {
	    dprintf("UART node not found");
	} else {
	    dprintf("Found UART node: %s\n", dt_node_get_name(uart));

	    buffer_t buffer = dt_prop_get(uart, "reg");
	    u64 val;
	    if (buffer_read_u64_be(buffer, 0, &val)) {
	        dprintf("UART base: 0x%lx\n", val);
	    } else {
	        dprintf("\"reg\" prop missing or invalid\n");
	    }
	}
	*/
	dprintf("Starting:\n");
	buffer_t x = dt_prop_get_immediate(fdt, "/reserved-memory", "ranges");

	if (buffer_is_valid(x))
		dprintf("Buffer ok\n");
	else
		dprintf("Buffer bad\n");

	// Showcasing that the tree works
	// dt_print_tree(root, 0);

	// dt_cleanup();
}
