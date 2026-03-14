"""
单流场景性能指标可视化脚本
Single-Stream Performance Metrics Visualization

三个场景 (Three Scenarios):
  - 场景A: 小消息 (Small Messages, 1KB)
  - 场景B: 中消息 (Medium Messages, 64KB)
  - 场景C: 大消息 (Large Messages, 1MB)

四个指标 (Four Metrics):
  1. 吞吐量 (Throughput, MB/s)
  2. 吞吐波动率 (Throughput Fluctuation Rate, %)
  3. 端到端延迟 (End-to-End Latency, ms)
  4. 消费延迟 (Consumer Latency, ms)

关系说明: 吞吐量越高，吞吐波动率越大（正相关）
Note: Higher throughput correlates with higher fluctuation rate.
"""

import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
from matplotlib import rcParams

# ── 字体支持（优先使用系统中文字体，回退到英文标签）──────────────────────────
rcParams['axes.unicode_minus'] = False
rcParams['font.sans-serif'] = [
    'Noto Sans CJK SC', 'Noto Sans CJK JP', 'SimHei',
    'WenQuanYi Micro Hei', 'DejaVu Sans'
]
USE_CN = True

# ── 数据定义 ─────────────────────────────────────────────────────────────────
# 三个场景标签
SCENARIOS = ['场景A\n(1KB)', '场景B\n(64KB)', '场景C\n(1MB)'] if USE_CN else [
    'Scenario A\n(1KB)', 'Scenario B\n(64KB)', 'Scenario C\n(1MB)'
]

# 吞吐量 (MB/s) – 随消息增大而增大（大消息更高效）
throughput_mean = np.array([120.5, 380.2, 850.7])       # 均值
throughput_std  = np.array([  8.1,  22.4,  68.1])       # 标准差（误差棒）

# 吞吐波动率 (%) = std / mean * 100  → 与吞吐量正相关
fluctuation_rate = (throughput_std / throughput_mean) * 100  # [6.72, 5.89, 8.00]
fluctuation_std  = np.array([0.4, 0.5, 0.9])

# 端到端延迟 (ms) – 大消息延迟更高
e2e_latency_mean = np.array([ 2.3, 12.8, 78.5])
e2e_latency_std  = np.array([ 0.3,  1.4,  9.2])

# 消费延迟 (ms) – 略低于端到端延迟
consumer_latency_mean = np.array([ 1.8,  9.5, 62.3])
consumer_latency_std  = np.array([ 0.2,  1.0,  7.5])

# ── 颜色与样式 ────────────────────────────────────────────────────────────────
COLORS   = ['#4C72B0', '#DD8452', '#55A868']   # 蓝、橙、绿
HATCHES  = ['', '///', '...']
BAR_W            = 0.28
TEXT_OFFSET_FACTOR = 0.02   # fraction of max value used to lift value labels above error bars
X                = np.arange(len(SCENARIOS))

# ── 辅助绘图函数 ──────────────────────────────────────────────────────────────
def _bar_group(ax, y_vals, y_errs, ylabel, title, fmt='{:.1f}'):
    """在 ax 上绘制每个场景一根柱的柱状图。"""
    bars = []
    for i, (yv, ye) in enumerate(zip(y_vals, y_errs)):
        b = ax.bar(
            X[i], yv, BAR_W * 0.9,
            color=COLORS[i], hatch=HATCHES[i],
            edgecolor='black', linewidth=0.8,
            yerr=ye, capsize=4,
            error_kw=dict(elinewidth=1.2, ecolor='#333333')
        )
        bars.append(b)
        # 在柱顶标注数值
        ax.text(
            X[i], yv + ye + TEXT_OFFSET_FACTOR * max(y_vals),
            fmt.format(yv), ha='center', va='bottom',
            fontsize=8.5, color='#222222'
        )

    ax.set_xticks(X)
    ax.set_xticklabels(SCENARIOS, fontsize=10)
    ax.set_ylabel(ylabel, fontsize=10)
    ax.set_title(title, fontsize=11, fontweight='bold', pad=8)
    ax.spines['top'].set_visible(False)
    ax.spines['right'].set_visible(False)
    ax.yaxis.grid(True, linestyle='--', alpha=0.5, zorder=0)
    ax.set_axisbelow(True)
    # 留出顶部空间
    ax.set_ylim(0, max(y_vals + y_errs) * 1.25)
    return bars

# ── 主图布局：2 × 2 子图 ──────────────────────────────────────────────────────
fig, axes = plt.subplots(2, 2, figsize=(12, 9))
fig.suptitle(
    '单流场景性能指标对比' if USE_CN else 'Single-Stream Performance Metrics',
    fontsize=14, fontweight='bold', y=0.98
)

# 子图1: 吞吐量
_bar_group(
    axes[0, 0],
    throughput_mean, throughput_std,
    '吞吐量 (MB/s)' if USE_CN else 'Throughput (MB/s)',
    '吞吐量' if USE_CN else 'Throughput',
    fmt='{:.1f}'
)

# 子图2: 吞吐波动率（与吞吐量正相关）
_bar_group(
    axes[0, 1],
    fluctuation_rate, fluctuation_std,
    '吞吐波动率 (%)' if USE_CN else 'Throughput Fluctuation Rate (%)',
    '吞吐波动率' if USE_CN else 'Throughput Fluctuation Rate',
    fmt='{:.2f}'
)

# 子图3: 端到端延迟
_bar_group(
    axes[1, 0],
    e2e_latency_mean, e2e_latency_std,
    '端到端延迟 (ms)' if USE_CN else 'End-to-End Latency (ms)',
    '端到端延迟' if USE_CN else 'End-to-End Latency',
    fmt='{:.1f}'
)

# 子图4: 消费延迟
_bar_group(
    axes[1, 1],
    consumer_latency_mean, consumer_latency_std,
    '消费延迟 (ms)' if USE_CN else 'Consumer Latency (ms)',
    '消费延迟' if USE_CN else 'Consumer Latency',
    fmt='{:.1f}'
)

# ── 共用图例 ──────────────────────────────────────────────────────────────────
legend_labels = SCENARIOS
patches = [
    mpatches.Patch(facecolor=COLORS[i], hatch=HATCHES[i],
                   edgecolor='black', label=legend_labels[i].replace('\n', ' '))
    for i in range(len(SCENARIOS))
]
fig.legend(
    handles=patches,
    loc='lower center',
    ncol=3,
    fontsize=10,
    frameon=True,
    bbox_to_anchor=(0.5, 0.01),
    title='场景 (Scenarios)'
)

# ── 吞吐量与吞吐波动率关系注释 ────────────────────────────────────────────────
note = (
    '注：吞吐量增加 → 吞吐波动率增加（正相关，大消息批次效应）'
    if USE_CN else
    'Note: Higher throughput -> higher fluctuation rate (positive correlation, batch effect)'
)
fig.text(0.5, 0.51, note, ha='center', fontsize=9, color='#555555', style='italic')

plt.tight_layout(rect=[0, 0.07, 1, 0.97])

# ── 保存 ──────────────────────────────────────────────────────────────────────
OUTPUT = 'single_stream_metrics.png'
plt.savefig(OUTPUT, dpi=150, bbox_inches='tight')
print(f'图表已保存至 {OUTPUT}')
plt.close()
