function solution(bandage, health, attacks) {
    let curTime = 0;
    let curHealth = health;
    const [time, recovery, bonusRecovery] = bandage;
    
    for (const [attackTime, damage] of attacks) {
        const timeDiff = attackTime - curTime - 1;
        const success = Math.floor(timeDiff / time);
        const totalRecovery = timeDiff * recovery + success * bonusRecovery;
        
        curHealth += totalRecovery;
        if(curHealth > health) curHealth = health;
        
        curHealth -= damage;
        
        if(curHealth <= 0) return -1;
        
        curTime = attackTime;
    }
    
    return curHealth;
}