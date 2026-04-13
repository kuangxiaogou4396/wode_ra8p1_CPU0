/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H
#ifdef __cplusplus
        extern "C" {
        #endif
/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
#define VECTOR_DATA_IRQ_COUNT    (15)
#endif
/* ISR prototypes */
void rm_ethosu_isr(void);
void ipc_isr(void);
void ceu_isr(void);
void drw_int_isr(void);
void glcdc_line_detect_isr(void);
void mipi_dsi_seq0_isr(void);
void mipi_dsi_seq1_isr(void);
void mipi_dsi_vin1_isr(void);
void mipi_dsi_rcv_isr(void);
void mipi_dsi_ferr_isr(void);
void mipi_dsi_ppi_isr(void);
void iic_master_rxi_isr(void);
void iic_master_txi_isr(void);
void iic_master_tei_isr(void);
void iic_master_eri_isr(void);

/* Vector table allocations */
#define VECTOR_NUMBER_NPU_IRQ ((IRQn_Type) 0) /* NPU IRQ (NPU IRQ) */
#define NPU_IRQ_IRQn          ((IRQn_Type) 0) /* NPU IRQ (NPU IRQ) */
#define VECTOR_NUMBER_IPC_IRQ1 ((IRQn_Type) 1) /* IPC IRQ1 (CPU Mutual Interrupt 1) */
#define IPC_IRQ1_IRQn          ((IRQn_Type) 1) /* IPC IRQ1 (CPU Mutual Interrupt 1) */
#define VECTOR_NUMBER_CEU_CEUI ((IRQn_Type) 2) /* CEU CEUI (CEU interrupt) */
#define CEU_CEUI_IRQn          ((IRQn_Type) 2) /* CEU CEUI (CEU interrupt) */
#define VECTOR_NUMBER_DRW_INT ((IRQn_Type) 3) /* DRW INT (DRW interrupt) */
#define DRW_INT_IRQn          ((IRQn_Type) 3) /* DRW INT (DRW interrupt) */
#define VECTOR_NUMBER_GLCDC_LINE_DETECT ((IRQn_Type) 4) /* GLCDC LINE DETECT (Specified line) */
#define GLCDC_LINE_DETECT_IRQn          ((IRQn_Type) 4) /* GLCDC LINE DETECT (Specified line) */
#define VECTOR_NUMBER_MIPIDSI_SEQ0 ((IRQn_Type) 5) /* MIPIDSI SEQ0 (Sequence operation channel 0 interrupt) */
#define MIPIDSI_SEQ0_IRQn          ((IRQn_Type) 5) /* MIPIDSI SEQ0 (Sequence operation channel 0 interrupt) */
#define VECTOR_NUMBER_MIPIDSI_SEQ1 ((IRQn_Type) 6) /* MIPIDSI SEQ1 (Sequence operation channel 1 interrupt) */
#define MIPIDSI_SEQ1_IRQn          ((IRQn_Type) 6) /* MIPIDSI SEQ1 (Sequence operation channel 1 interrupt) */
#define VECTOR_NUMBER_MIPIDSI_VIN1 ((IRQn_Type) 7) /* MIPIDSI VIN1 (Video-Input operation channel1 interrupt) */
#define MIPIDSI_VIN1_IRQn          ((IRQn_Type) 7) /* MIPIDSI VIN1 (Video-Input operation channel1 interrupt) */
#define VECTOR_NUMBER_MIPIDSI_RCV ((IRQn_Type) 8) /* MIPIDSI RCV (DSI packet receive interrupt) */
#define MIPIDSI_RCV_IRQn          ((IRQn_Type) 8) /* MIPIDSI RCV (DSI packet receive interrupt) */
#define VECTOR_NUMBER_MIPIDSI_FERR ((IRQn_Type) 9) /* MIPIDSI FERR (DSI fatal error interrupt) */
#define MIPIDSI_FERR_IRQn          ((IRQn_Type) 9) /* MIPIDSI FERR (DSI fatal error interrupt) */
#define VECTOR_NUMBER_MIPIDSI_PPI ((IRQn_Type) 10) /* MIPIDSI PPI (DSI D-PHY PPI interrupt) */
#define MIPIDSI_PPI_IRQn          ((IRQn_Type) 10) /* MIPIDSI PPI (DSI D-PHY PPI interrupt) */
#define VECTOR_NUMBER_IIC1_RXI ((IRQn_Type) 11) /* IIC1 RXI (Receive data full) */
#define IIC1_RXI_IRQn          ((IRQn_Type) 11) /* IIC1 RXI (Receive data full) */
#define VECTOR_NUMBER_IIC1_TXI ((IRQn_Type) 12) /* IIC1 TXI (Transmit data empty) */
#define IIC1_TXI_IRQn          ((IRQn_Type) 12) /* IIC1 TXI (Transmit data empty) */
#define VECTOR_NUMBER_IIC1_TEI ((IRQn_Type) 13) /* IIC1 TEI (Transmit end) */
#define IIC1_TEI_IRQn          ((IRQn_Type) 13) /* IIC1 TEI (Transmit end) */
#define VECTOR_NUMBER_IIC1_ERI ((IRQn_Type) 14) /* IIC1 ERI (Transfer error) */
#define IIC1_ERI_IRQn          ((IRQn_Type) 14) /* IIC1 ERI (Transfer error) */
/* The number of entries required for the ICU vector table. */
#define BSP_ICU_VECTOR_NUM_ENTRIES (15)

#ifdef __cplusplus
        }
        #endif
#endif /* VECTOR_DATA_H */
