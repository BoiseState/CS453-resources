# Crystal sum program

def sum(seq)
    s=0
    seq.each do |v|
        s+=v
    end
    return s
end

seq=[5,6,1,8,3,7]
puts sum(seq)
